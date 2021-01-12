#pragma once
#include <unordered_map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
private:
	struct ShaderProgramSource
	{
		std::string VertexSource;
		std::string FragmentSource;
	};

	std::string m_FilePath;
	unsigned int m_RendererID;
	std::unordered_map<std::string, int> m_UniformLocationCache;
public:
	Shader(const std::string& filename);
	~Shader();

	void Bind() const;
	void Unbind() const;

	// Set uniforms
	void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3 );
private:

	ShaderProgramSource ParseShader(const std::string& filePath);
	unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	unsigned int ComplieShader(unsigned int type, const std::string& source);
	int GetUniformLocation(const std::string& name);
};
