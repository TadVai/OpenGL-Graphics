#include "Common.h"
#include "Cube.h"
#define BUFFER_OFFSET(i) ((char *)NULL + (i))


CCube::CCube()
{}

CCube::~CCube()
{}


// Create the cube, including its geometry, texture mapping, normal, and colour
void CCube::Create(string directory, string filename, float edge_length, float textureRepeat)
{

	m_edge_length = edge_length;

	// Load the texture
	m_texture.Load(directory + filename, true);

	m_directory = directory;
	m_filename = filename;

	// Set parameters for texturing using sampler object
	m_texture.SetSamplerObjectParameter(GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	m_texture.SetSamplerObjectParameter(GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	m_texture.SetSamplerObjectParameter(GL_TEXTURE_WRAP_S, GL_REPEAT);
	m_texture.SetSamplerObjectParameter(GL_TEXTURE_WRAP_T, GL_REPEAT);


	// Use VAO to store state associated with vertices
	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);

	// Create a VBO
	m_vbo.Create();
	m_vbo.Bind();


	// Vertex positions
	glm::vec3 cubeVertices[36] =
	{
	glm::vec3(-m_edge_length,-m_edge_length,-m_edge_length),    // triangle 1 
	glm::vec3(-m_edge_length,-m_edge_length, m_edge_length),
	glm::vec3(-m_edge_length, m_edge_length, m_edge_length), 
	
	glm::vec3(-m_edge_length,-m_edge_length,-m_edge_length),	// triangle 2 
	glm::vec3(-m_edge_length, m_edge_length, m_edge_length),
	glm::vec3(-m_edge_length, m_edge_length,-m_edge_length),


	glm::vec3(m_edge_length, m_edge_length,-m_edge_length),		// triangle 3 
	glm::vec3(-m_edge_length,-m_edge_length,-m_edge_length),
	glm::vec3(-m_edge_length, m_edge_length,-m_edge_length),

	glm::vec3(m_edge_length, m_edge_length,-m_edge_length),		// triangle 4 
	glm::vec3(m_edge_length,-m_edge_length,-m_edge_length),
	glm::vec3(-m_edge_length,-m_edge_length,-m_edge_length),


	glm::vec3(-m_edge_length, m_edge_length, m_edge_length),	// triangle 5 
	glm::vec3(-m_edge_length,-m_edge_length, m_edge_length),
	glm::vec3(m_edge_length,-m_edge_length, m_edge_length),

	glm::vec3(m_edge_length, m_edge_length, m_edge_length),		// triangle 6 
	glm::vec3(-m_edge_length, m_edge_length, m_edge_length),
	glm::vec3(m_edge_length,-m_edge_length, m_edge_length),


	glm::vec3(m_edge_length,-m_edge_length,-m_edge_length),		// triangle 7
	glm::vec3(m_edge_length, m_edge_length, m_edge_length),
	glm::vec3(m_edge_length,-m_edge_length, m_edge_length),

	glm::vec3(m_edge_length, m_edge_length, m_edge_length),		// triangle 8 
	glm::vec3(m_edge_length,-m_edge_length,-m_edge_length),
	glm::vec3(m_edge_length, m_edge_length,-m_edge_length),


	glm::vec3(m_edge_length, m_edge_length, m_edge_length),		// triangle 9 
	glm::vec3(m_edge_length, m_edge_length,-m_edge_length),
	glm::vec3(-m_edge_length, m_edge_length,-m_edge_length),

	glm::vec3(m_edge_length, m_edge_length, m_edge_length),		// triangle 10
	glm::vec3(-m_edge_length, m_edge_length,-m_edge_length),
	glm::vec3(-m_edge_length, m_edge_length, m_edge_length),


	glm::vec3(m_edge_length,-m_edge_length, m_edge_length),		// triangle 11
	glm::vec3(-m_edge_length,-m_edge_length,-m_edge_length),
	glm::vec3(m_edge_length,-m_edge_length,-m_edge_length),

	glm::vec3(m_edge_length,-m_edge_length, m_edge_length),		// triangle 12 
	glm::vec3(-m_edge_length,-m_edge_length, m_edge_length),
	glm::vec3(-m_edge_length,-m_edge_length,-m_edge_length),

	};

	// Texture coordinates
	glm::vec2 cubeTexCoords[36] =
	{
		// Wall 1
		glm::vec2(0.0f, 0.0f),
		glm::vec2(textureRepeat, 0.0f),
		glm::vec2(textureRepeat, textureRepeat),

		glm::vec2(0.0f, 0.0f),
		glm::vec2(textureRepeat, textureRepeat),
		glm::vec2(0.0f, textureRepeat),
		

		// Wall 2
		glm::vec2(0.0f, textureRepeat),
		glm::vec2(textureRepeat, 0.0f),
		glm::vec2(textureRepeat, textureRepeat),

		glm::vec2(0.0f, textureRepeat),
		glm::vec2(0.0f, 0.0f),
		glm::vec2(textureRepeat,0.0f),

		//Wall 3
		glm::vec2(0.0f, textureRepeat),
		glm::vec2(0.0f, 0.0f),
		glm::vec2(textureRepeat, 0.0f),
		
		glm::vec2(textureRepeat,0.0f),
		glm::vec2(0.0f, 0.0f),
		glm::vec2(textureRepeat, textureRepeat),
		
	

		//Wall 4
		glm::vec2(0.0f, 0.0f),
		glm::vec2(textureRepeat, textureRepeat),
		glm::vec2(textureRepeat,0.0f),
		
		glm::vec2(0.0f, textureRepeat),
		glm::vec2(textureRepeat, 0.0f),
		glm::vec2(textureRepeat, textureRepeat),

		
		//Roof
		//glm::vec2(0.0f,textureRepeat),
		//glm::vec2(textureRepeat, 0.0f),		
		//glm::vec2(textureRepeat, textureRepeat),
		//

		//glm::vec2(0.0f, textureRepeat),
		//glm::vec2(textureRepeat, 0.0f),
		//glm::vec2(textureRepeat, textureRepeat),

		//glm::vec2(0.0f, 0.0f),
		//glm::vec2(0.0f, textureRepeat),
		//glm::vec2(textureRepeat, 0.0f),
		//glm::vec2(textureRepeat, textureRepeat),
		//glm::vec2(0.0f, 0.0f),
		//glm::vec2(0.0f, textureRepeat),
		//glm::vec2(textureRepeat, 0.0f),
		//glm::vec2(textureRepeat, textureRepeat),
		//glm::vec2(0.0f, 0.0f),
		//glm::vec2(0.0f, textureRepeat),
		//glm::vec2(textureRepeat, 0.0f),
		//glm::vec2(textureRepeat, textureRepeat)


	};

	// Cube normal
	glm::vec3 cubeNormal = glm::vec3(0.0f, 1.0f, 0.0f);

	// Put the vertex attributes in the VBO
	for (unsigned int i = 0; i < 36; i++) {
		m_vbo.AddData(&cubeVertices[i], sizeof(glm::vec3));
		m_vbo.AddData(&cubeTexCoords[i], sizeof(glm::vec2));
		m_vbo.AddData(&cubeNormal, sizeof(glm::vec3));
	}


	// Upload the VBO to the GPU
	m_vbo.UploadDataToGPU(GL_STATIC_DRAW);

	// Set the vertex attribute locations
	GLsizei istride = 2 * sizeof(glm::vec3) + sizeof(glm::vec2);

	// Vertex positions
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, istride, 0);
	// Texture coordinates
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, istride, (void*)sizeof(glm::vec3));
	// Normal vectors
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, istride, (void*)(sizeof(glm::vec3) + sizeof(glm::vec2)));

}

// Render the cube as a triangle strip
void CCube::Render()
{
	glBindVertexArray(m_vao);
	m_texture.Bind();
	glDrawArrays(GL_TRIANGLES, 0, 36);

}

// Release resources
void CCube::Release()
{
	m_texture.Release();
	glDeleteVertexArrays(1, &m_vao);
	m_vbo.Release();
}