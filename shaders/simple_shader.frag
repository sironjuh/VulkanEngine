#version 450

layout (location = 0) in vec4 fragColor;
layout (location = 0) out vec4 outColor;

in vec4 gl_FragCoord;

vec2 u_resolution = vec2(1600, 1200);
float u_time = 0.0;

float sdSphere(vec3 p, vec3 pos, float radius) {
    p -= pos;
    return length(p) - radius;
}

float sdTorus(vec3 p, vec2 t) {
  vec2 q = vec2(length(p.xz)-t.x,p.y);
  return length(q)-t.y;
}

float sdBox(vec3 p, vec3 b) {
  vec3 q = abs(p) - b;
  return length(max(q,0.0)) + min(max(q.x,max(q.y,q.z)),0.0);
}

mat4 rotationMatrix(vec3 axis, float angle) {
    axis = normalize(axis);
    float s = sin(angle);
    float c = cos(angle);
    float oc = 1.0 - c;
    
    return mat4(oc * axis.x * axis.x + c,           oc * axis.x * axis.y - axis.z * s,  oc * axis.z * axis.x + axis.y * s,  0.0,
                oc * axis.x * axis.y + axis.z * s,  oc * axis.y * axis.y + c,           oc * axis.y * axis.z - axis.x * s,  0.0,
                oc * axis.z * axis.x - axis.y * s,  oc * axis.y * axis.z + axis.x * s,  oc * axis.z * axis.z + c,           0.0,
                0.0,                                0.0,                                0.0,                                1.0);
}

vec3 rotate(vec3 v, vec3 axis, float angle) {
	mat4 m = rotationMatrix(axis, angle);
	return (m * vec4(v, 1.0)).xyz;
}

/*float displacement(vec3 p) {
    float m = 2. * sin(u_time / 2.);
    return sin(m * p.x) * sin(m * p.y) * sin(m * p.z);
}*/

float displacement(vec3 p) {
    return sin(2. * p.x) * sin(2. * p.y) * sin(2. * p.z);
}

float sdf(vec3 p) {
    vec3 p1 = rotate(p, vec3(sin(u_time), cos(u_time), 1.), u_time / 2.);
    float sphere = sdSphere(p1, vec3(0.), 0.5);
    float box = sdBox(p1, vec3(.3));
    //float torus = sdTorus(p1, vec2(.5, .15));
    
    float d = displacement(p1 - vec3(0.));
    return mix(sphere, d, 0.5); 
}

// https://www.iquilezles.org/www/articles/normalsSDF/normalsSDF.htm
vec3 calcNormal(in vec3 p) {
    const float eps = 0.001;
    const vec2 h = vec2(eps,0);
    return normalize(vec3(sdf(p+h.xyy) - sdf(p-h.xyy),
                          sdf(p+h.yxy) - sdf(p-h.yxy),
                          sdf(p+h.yyx) - sdf(p-h.yyx)));
}

void main() {
    vec2 uv = (2. * gl_FragCoord.xy - u_resolution.xy) / u_resolution.y;
    vec2 stretched_uv = (gl_FragCoord.xy / u_resolution.xy) - vec2(.5);
    vec3 camPos = vec3(0., 0., 2);
    vec3 rayDir = normalize(vec3(uv, -2));

    float dist = 0.;
    float distMax = 4.;
    vec3 currentPos;
    
    // raymarch, limit to 100 iterations
    for(int i = 0; i < 100; ++i) {
        currentPos = camPos + dist * rayDir;
        float h = sdf(currentPos); //abs to peek inside
        dist += h;
        if(h < 0.004 || dist > distMax) break;
    }

    // add some gradient on background (solid value in css .00625)
    vec3 color = vec3(.5 - length(stretched_uv - vec2(0.)));
    
    if(dist < distMax) {
        vec3 normal = calcNormal(currentPos);
        //float diffuse = dot(normalize(vec3(3.)), normal);
        color = vec3(normal);
    }

    //outColor = vec4(color, 1.);
    outColor = fragColor;
}
