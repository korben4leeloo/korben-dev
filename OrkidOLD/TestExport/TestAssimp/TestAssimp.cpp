#include <assimp/scene.h>
#include <assimp/Importer.hpp>

int main()
{
	Assimp::Importer importer;

	const aiScene* pScene = importer.ReadFile( "C:\\Users\\jj\\Documents\\maya\\projects\\default\\scenes\\testcubetriangular.dae", 0 );
	return	( 0 );
}