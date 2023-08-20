#pragma once

#include <vector>
#include <string>

#include <assimp\Importer.hpp>
#include <assimp\scene.h>
#include <assimp\postprocess.h>

#include <Mesh.hpp>
#include <Texture.hpp>

class Model {
public:
	Model();

	void LoadModel(std::string const& fileName);
	void RenderModel();
	void ClearModel();

	~Model();

private:
	void LoadNode(aiNode* node, aiScene const* scene);
	void LoadMesh(aiMesh* mesh, aiScene const* scene);
	void LoadMaterials(aiScene const* scene);

	std::vector<Mesh*> meshList;
	std::vector<Texture*> textureList;
	std::vector<unsigned int> meshToTexture;
};