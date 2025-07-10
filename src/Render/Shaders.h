#pragma once

#include <string>
#include <glad/glad.h>
#include <iostream>


namespace Render{
	class ProgramShader {
		bool is_Compiled{ false };
		GLuint m_id{ 0 };
		bool createShader(const std::string& src, const GLenum shaderType, GLuint& shader_id);

	public:
		ProgramShader(const std::string& ver_shader, const std::string& fr_shader);
		~ProgramShader();
		bool get_compile() const { return is_Compiled; };
		bool use_shaders();

	};
}
