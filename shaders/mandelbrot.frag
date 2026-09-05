#version 120

uniform vec2 resolution;
uniform vec2 minBounds;
uniform vec2 maxBounds;

void main()
{
    vec2 position = gl_FragCoord.xy / resolution;

    float a = minBounds.x + position.x * (maxBounds.x - minBounds.x);
    float b = minBounds.y + position.y * (maxBounds.y - minBounds.y);
    
    float zA = 0.0;
    float zB = 0.0;

    int iterations = 0;
    const int maxIterations = 500;

    for (int i = 0; i < maxIterations; i++)
    {
        if (zA * zA + zB * zB > 4.0)
        {
            break;
        }

        float nextZA = zA * zA - zB * zB + a;
        float nextZB = 2.0 * zA * zB + b;

        zA = nextZA;
        zB = nextZB;
        iterations++;
    }

    float brightness = float(iterations) / float(maxIterations);

    if (iterations == maxIterations)
    {
        brightness = 0.0;
    }

    gl_FragColor = vec4(brightness, brightness, brightness, 1.0);
}