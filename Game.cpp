#include "Game.h"

//-----------------------------------------------------------------------------
Game *Game::mInstance = NULL;

//-----------------------------------------------------------------------------
Game* Game::getInstance()
{
	if (mInstance == nullptr)
	{
		mInstance = new Game();
	}

	return mInstance;
}

//-----------------------------------------------------------------------------
void Game::destroyInstance()
{
	if (mInstance)
		delete mInstance;
}

//-----------------------------------------------------------------------------
Game::Game(void)
{
	mOgreRoot = NULL;
	mOgreRoot = new Ogre::Root();
	mSceneManager = NULL;
	mWindow = NULL;
	mCamera = NULL;
	mViewport = NULL;
}

//-----------------------------------------------------------------------------
Game::~Game(void)
{
	//destroyInput();

	if (mViewport)
		delete mViewport;

	if (mCamera)
		delete mCamera;

	if (mSceneManager)
		delete mSceneManager;

	if (mWindow)
		delete mWindow;

	if (mOgreRoot)
		delete mOgreRoot;
}

//-----------------------------------------------------------------------------
void Game::run()
{
	if(!mOgreRoot)
        return;//!Error
    if(!mOgreRoot->showConfigDialog())
        return;
    mOgreRoot->initialise(true, "OgreWindow");

	createWindow();
	createSceneManager();
	createCamera();
	createViewport();
	//createInput();
	setupResourceManager();

	Ogre::Entity *ogreHead = mSceneManager->createEntity("OgreHead", "ogrehead.mesh");	
	Ogre::SceneNode *ogreNode = mSceneManager->getRootSceneNode()->createChildSceneNode("Head Node", Ogre::Vector3(-50.0f, 30.0f, 0.0f));
	ogreNode->yaw(Ogre::Degree(-30.0f));
	ogreNode->attachObject(ogreHead);
	ogreHead->setCastShadows(true);

	Ogre::Entity *ogreHead1 = mSceneManager->createEntity("OgreHead1", "ogrehead.mesh");
	Ogre::SceneNode *ogreNode1 = mSceneManager->getRootSceneNode()->createChildSceneNode("Head Node 1", Ogre::Vector3(80, 40, -10));
	ogreNode1->setScale(1.5f, 1.5f, 1.5f);
	ogreNode1->attachObject(ogreHead1);

	Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);
	Ogre::MeshManager::getSingleton().createPlane(
		"ground",
		Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
		plane, 
		1500, 1500, 20, 20, 
		true, 
		1, 5, 5, 
		Ogre::Vector3::UNIT_Z);
	Ogre::Entity* groundEntity = mSceneManager->createEntity("ground");
	mSceneManager->getRootSceneNode()->createChildSceneNode()->attachObject(groundEntity);
	groundEntity->setCastShadows(false);
	groundEntity->setMaterialName("Examples/Rockwall");

	Ogre::Light* spotLight = mSceneManager->createLight("SpotLight");
	spotLight->setDiffuseColour(0, 0, 1.0);
	spotLight->setSpecularColour(0, 0, 1.0);
	spotLight->setType(Ogre::Light::LT_SPOTLIGHT);
	spotLight->setDirection(-1, -1, 0);
	spotLight->setPosition(Ogre::Vector3(200, 200, 0));
	spotLight->setSpotlightRange(Ogre::Degree(35), Ogre::Degree(50));

	Ogre::Light* directionalLight = mSceneManager->createLight("DirectionalLight");
	directionalLight->setType(Ogre::Light::LT_DIRECTIONAL);
	directionalLight->setDiffuseColour(Ogre::ColourValue(.4, 0, 0));
	directionalLight->setSpecularColour(Ogre::ColourValue(.4, 0, 0));
	directionalLight->setDirection(Ogre::Vector3(0, -1, 1));

	mOgreRoot->addFrameListener(this);

    mOgreRoot->startRendering();
}

//-----------------------------------------------------------------------------
void Game::createWindow()
{
	if (mOgreRoot != NULL)
		mWindow = mOgreRoot->getAutoCreatedWindow();
}
	
//-----------------------------------------------------------------------------
void Game::createCamera()
{
	if (mSceneManager != NULL)
	{
		mCamera = mSceneManager->createCamera("MainCamera");	
		mCamera->setPosition(Ogre::Vector3(0, 300, 300));
		mCamera->lookAt(Ogre::Vector3(0, 0, 0));
		mCamera->setNearClipDistance(5);
	}
}

//-----------------------------------------------------------------------------
void Game::createSceneManager()
{
	if (mOgreRoot != NULL)
	{
		mSceneManager = mOgreRoot->createSceneManager(Ogre::ST_GENERIC, "MainSceneManager");
		mSceneManager->setAmbientLight(Ogre::ColourValue(0.5f, 0.5f, 0.5f));
		mSceneManager->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_ADDITIVE);
	}
}

//-----------------------------------------------------------------------------
void Game::createViewport()
{
	if (mWindow != NULL && mCamera != NULL)
	{
		mViewport = mWindow->addViewport(mCamera);
		mViewport->setBackgroundColour(Ogre::ColourValue(0.0f, 0.0f, 0.0f));
		mCamera->setAspectRatio(Ogre::Real(mViewport->getActualWidth()) / Ogre::Real(mViewport->getActualHeight()));
	}
}

//-----------------------------------------------------------------------------
void Game::setupResourceManager()
{
	Ogre::ResourceGroupManager::getSingleton().addResourceLocation("D:\\Projects\\Ogre3D\\Ogre3D_001\\resource", "FileSystem", "General");
	Ogre::ResourceGroupManager::getSingleton().initialiseResourceGroup("General");
	Ogre::ResourceGroupManager::getSingleton().loadResourceGroup("General");
}

bool Game::frameStarted(const Ogre::FrameEvent &fe)
{
	if (mWindow->isClosed())
		return false;
	//captureInput();
	return true;
}

bool Game::frameEnded(const Ogre::FrameEvent &fe)
{
	return true;
}

/*
void Game::captureInput()
{
	if (mMouse != NULL)
		mMouse->capture();
	if (mKeyboard != NULL)
		mKeyboard->capture();
}

void Game::createInput()
{
	OIS::ParamList pl;
    size_t windowHnd = 0;
    std::ostringstream windowHndStr;
 
    mWindow->getCustomAttribute("WINDOW", &windowHnd);
    windowHndStr << windowHnd;
    pl.insert(std::make_pair(std::string("WINDOW"), windowHndStr.str()));
 
    mInputManager = OIS::InputManager::createInputSystem( pl );
 
    //!Create all devices.
    mKeyboard = static_cast<OIS::Keyboard*>(mInputManager->createInputObject( OIS::OISKeyboard, true ));
    mMouse = static_cast<OIS::Mouse*>(mInputManager->createInputObject( OIS::OISMouse, true ));
 
    unsigned int width, height, depth;
    int left, top;
    mWindow->getMetrics(width, height, depth, left, top);
    mMouse->getMouseState().width = width;
    mMouse->getMouseState().height = height;
}

void Game::destroyInput()
{
	if (mMouse != NULL)
		mInputManager->destroyInputObject(mMouse);
	if (mKeyboard != NULL)
		mInputManager->destroyInputObject(mKeyboard);
	OIS::InputManager::destroyInputSystem(mInputManager);
	mInputManager = NULL;
}*/
