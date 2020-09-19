#version 330 core


out vec4 fragColor;


uniform vec4 RColor;

//in vec3 ourColor;


void main()
{
//	fragColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);
	
	fragColor = RColor;
	
	
}