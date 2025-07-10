#include "Shaders.h"

bool Render::ProgramShader::createShader(const std::string& src, const GLenum shaderType, GLuint& shader_id)
{
	shader_id = glCreateShader(shaderType);
	const char* temp = src.c_str();
	glShaderSource(shader_id, 1, &temp, nullptr);
	glCompileShader(shader_id);
	// ������� �������� � ���������� ����������
}


Render::ProgramShader::ProgramShader(const std::string& ver_shader, const std::string& fr_shader)
{
	GLuint vs = 0, fr = 0;
	createShader(ver_shader, GL_VERTEX_SHADER, vs);
	createShader(fr_shader, GL_FRAGMENT_SHADER, fr);
	// ������� �������� � ���������� ����������
}