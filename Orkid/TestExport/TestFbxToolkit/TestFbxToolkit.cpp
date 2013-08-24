#include <fbxsdk.h>

int main()
{
	// Create the FBX SDK manager
	FbxManager* lSdkManager = FbxManager::Create();

	// Create an IOSettings object.
	FbxIOSettings * ios = FbxIOSettings::Create(lSdkManager, IOSROOT );
	lSdkManager->SetIOSettings(ios);

	// ... Configure the FbxIOSettings object ...

	// Create an importer.
	FbxImporter* lImporter = FbxImporter::Create(lSdkManager, "");

	// Declare the path and filename of the file containing the scene.
	// In this case, we are assuming the file is in the same directory as the executable.
	const char* lFilename = "C:\\Users\\jj\\Documents\\maya\\projects\\default\\scenes\\testcube2.fbx";

	// Initialize the importer.
	bool lImportStatus = lImporter->Initialize(lFilename, -1, lSdkManager->GetIOSettings());

	if(!lImportStatus)
	{
		printf("Call to FbxImporter::Initialize() failed.\n");
		//printf("Error returned: %s\n\n", lImporter->GetLastErrorString());
		exit(-1);
	}

	// Create a new scene so it can be populated by the imported file.
	FbxScene* lScene = FbxScene::Create(lSdkManager,"myScene");

	// Import the contents of the file into the scene.
	lImporter->Import(lScene);

	FbxNode* pRootNode = lScene->GetRootNode();

	int nChildCount = pRootNode->GetChildCount();

	for	( int i = 0; i < nChildCount; i++ )
	{
		FbxNode* pChildNode = pRootNode->GetChild( i );
		
		FbxDouble3 translation = pChildNode->LclTranslation.Get();
		FbxDouble3 rotation = pChildNode->LclRotation.Get();
		FbxDouble3 scaling = pChildNode->LclScaling.Get();

		int nNodeAttrCount = pChildNode->GetNodeAttributeCount();

		for	( int j = 0; j < nChildCount; j++ )
		{
			FbxNodeAttribute* pNodeAttr = pChildNode->GetNodeAttributeByIndex( j );
			FbxNodeAttribute::EType eNodeAttrType = pNodeAttr->GetAttributeType();

			if	( eNodeAttrType == FbxNodeAttribute::eMesh )
			{
				FbxMesh* pMesh = (FbxMesh*)pNodeAttr;
				int k = 0;
			}
		}

		
	}

	return	( 0 );
}