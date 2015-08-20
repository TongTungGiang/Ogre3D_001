#include "Game.h"

int main()
{
	Game::getInstance()->run();

	return 0;
	//Ogre::Root *root = new Ogre::Root();
	//if (!root->showConfigDialog())
	//	return 1;
	//root->initialise(true, "Hello World!");
	//
	//Ogre::RenderWindow *window = root->getAutoCreatedWindow();

	////-----------------------------------------------
	//Ogre::SceneManager *sceneManager =  root->createSceneManager(Ogre::ST_GENERIC, "SceneManager");
	//sceneManager->setAmbientLight(Ogre::ColourValue(0.5f, 0.5f, 0.5f));
	//sceneManager->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_ADDITIVE);
	//
	//Ogre::Camera *cam = sceneManager->createCamera("MainCamera");
	//cam->setPosition(Ogre::Vector3(0, 300, 300));
	//cam->lookAt(Ogre::Vector3(0, 0, 0));
	//cam->setNearClipDistance(5);

	//Ogre::Viewport *vp = window->addViewport(cam);
	//vp->setBackgroundColour(Ogre::ColourValue(0.0f, 0.0f, 0.0f));

	//cam->setAspectRatio(Ogre::Real(vp->getActualWidth()) / Ogre::Real(vp->getActualHeight()));
	//
	//Ogre::ResourceGroupManager::getSingleton().addResourceLocation("D:\\Projects\\Ogre3D\\Ogre3D_001\\resource", "FileSystem", "General");
	//Ogre::ResourceGroupManager::getSingleton().initialiseResourceGroup("General");
	//Ogre::ResourceGroupManager::getSingleton().loadResourceGroup("General");

	////---------------------------------
	//Ogre::Entity *ogreHead = sceneManager->createEntity("OgreHead", "ogrehead.mesh");	
	//Ogre::SceneNode *ogreNode = sceneManager->getRootSceneNode()->createChildSceneNode("Head Node", Ogre::Vector3(-50.0f, 30.0f, 0.0f));
	//ogreNode->yaw(Ogre::Degree(-30.0f));
	//ogreNode->attachObject(ogreHead);
	//ogreHead->setCastShadows(true);

	//Ogre::Entity *ogreHead1 = sceneManager->createEntity("OgreHead1", "ogrehead.mesh");
	//Ogre::SceneNode *ogreNode1 = sceneManager->getRootSceneNode()->createChildSceneNode("Head Node 1", Ogre::Vector3(80, 40, -10));
	//ogreNode1->setScale(1.5f, 1.5f, 1.5f);
	//ogreNode1->attachObject(ogreHead1);

	//Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);
	//Ogre::MeshManager::getSingleton().createPlane(
	//	"ground",
	//	Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
	//	plane, 
	//	1500, 1500, 20, 20, 
	//	true, 
	//	1, 5, 5, 
	//	Ogre::Vector3::UNIT_Z);
	//Ogre::Entity* groundEntity = sceneManager->createEntity("ground");
	//sceneManager->getRootSceneNode()->createChildSceneNode()->attachObject(groundEntity);
	//groundEntity->setCastShadows(false);
	//groundEntity->setMaterialName("Examples/Rockwall");

	//Ogre::Light* spotLight = sceneManager->createLight("SpotLight");
	//spotLight->setDiffuseColour(0, 0, 1.0);
	//spotLight->setSpecularColour(0, 0, 1.0);
	//spotLight->setType(Ogre::Light::LT_SPOTLIGHT);
	//spotLight->setDirection(-1, -1, 0);
	//spotLight->setPosition(Ogre::Vector3(200, 200, 0));
	//spotLight->setSpotlightRange(Ogre::Degree(35), Ogre::Degree(50));

	//Ogre::Light* directionalLight = sceneManager->createLight("DirectionalLight");
	//directionalLight->setType(Ogre::Light::LT_DIRECTIONAL);
	//directionalLight->setDiffuseColour(Ogre::ColourValue(.4, 0, 0));
	//directionalLight->setSpecularColour(Ogre::ColourValue(.4, 0, 0));
	//directionalLight->setDirection(Ogre::Vector3(0, -1, 1));

	////------------------------------------------------	
	//root->startRendering();

}