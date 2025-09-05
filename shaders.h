#ifndef SHADERS_H
#define SHADERS_H

#include <include/gl.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader {
public:
  GLuint ID;

  Shader(const char* vertex_path, const char* fragment_path);

  void Use();
  void SetBool(const std::string& name, bool value) const;
  void SetInt(const std::string& name, int value) const;
  void SetFloat(const std::string& name, float value) const;
private:
  void CompileShaders(const char* vertex_shader_code, const char* fragment_shader_code);
};

Shader::Shader(const char* vertex_path, const char* fragment_path) {
  std::string vertex_code;
  std::string fragment_code;
  std::ifstream vertex_shader_file;
  std::ifstream fragment_shader_file;

  vertex_shader_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  fragment_shader_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

  try {
    vertex_shader_file.open(vertex_path);
    fragment_shader_file.open(fragment_path);
    std::stringstream vertex_shader_stream, fragment_shader_stream;

    vertex_shader_stream << vertex_shader_file.rdbuf();
    fragment_shader_stream << fragment_shader_file.rdbuf();

    vertex_shader_file.close();
    fragment_shader_file.close();

    vertex_code = vertex_shader_stream.str();
    fragment_code = fragment_shader_stream.str();
  } catch (std::ifstream::failure) {
    std::cout << "ERROR::Shader filie not open" << std::endl;
  }

  CompileShaders(vertex_code.c_str(), fragment_code.c_str());
}

void Shader::CompileShaders(const char* vertex_shader_code, const char* fragment_shader_code) {
  GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
  GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);

  glShaderSource(vertex_shader, 1, &vertex_shader_code, NULL);
  glShaderSource(fragment_shader, 1, &fragment_shader_code, NULL);
  glCompileShader(vertex_shader);
  glCompileShader(fragment_shader);

  int success;
  char info_log[512];
  glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);

  if(!success) {
    glGetShaderInfoLog(vertex_shader, sizeof(info_log), NULL, info_log);
    std::cout << "ERROR COMPIILE: " << info_log << std::endl;
  }

  glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
  if(!success) {
    glGetShaderInfoLog(fragment_shader, sizeof(info_log), NULL, info_log);
    std::cout << "ERROR COMPIILE: " << info_log << std::endl;
  }

  ID = glCreateProgram();
  glAttachShader(ID, vertex_shader);
  glAttachShader(ID, fragment_shader);
  glLinkProgram(ID);

  glGetProgramiv(ID, GL_LINK_STATUS, &success);
  if(!success) {
    glGetProgramInfoLog(ID, sizeof(info_log), NULL, info_log);
    std::cout << "ERROR LINK: " << info_log << std::endl;
  }

  glDeleteShader(vertex_shader);
  glDeleteShader(fragment_shader);
}

void Shader::Use() {
  glUseProgram(ID);
}

void Shader::SetBool(const std::string& name, bool value) const {
  glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}

void Shader::SetInt(const std::string& name, int value) const {
  glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::SetFloat(const std::string& name, float value) const {
  glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

#endif // SHADERS_H