#version 330 core

// color
out vec4 fragColor;

// textures
in vec2 TexCoord;

// setup uniforms
uniform vec4 RColor;

uniform sampler2D ourTexture;


//in vec3 ourColor;


void main()
{
//	fragColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);
	fragColor = RColor;
	fragColor = texture(ourTexture, TexCoord);
	
}