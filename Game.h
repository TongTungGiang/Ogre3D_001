#ifndef GAME_H
#define GAME_H

// Ogre's header files
#include <OGRE/Ogre.h>
#include <OGRE/OgreSceneManager.h>
#include <OIS/OIS.h>

// STL's header files
#include <string>

// Game class
// This is a singleton class for a main game.
class Game : public Ogre::FrameListener
{

//----------------------------------
private:

	// Class constructor, it is private because the class is singleton
	Game(void);
	
	// Class destructor, it is private because the class is singleton
	~Game(void);

	// Singleton instance
	static Game *mInstance;

	// Ogre root: the entry point of Ogre3D
	Ogre::Root *mOgreRoot;

	// Ogre render window
	Ogre::RenderWindow *mWindow;

	// Ogre camera
	Ogre::Camera *mCamera;

	// Ogre scene manager
	Ogre::SceneManager *mSceneManager;

	// Ogre viewport
	Ogre::Viewport *mViewport;

	//
	//bool processUnbufferedInput(const Ogre::FrameEvent& fe);


//----------------------------------
public:

	// Destroy the singleton instance
	static void destroyInstance();

	// Get the singleton instance
	static Game *getInstance();

	// Run the game
	void run();

	// Create the window
	void createWindow();

	// Create the scene manager
	void createSceneManager();

	// Create the viewport
	void createViewport();

	// Create the camera
	void createCamera();

	// Setup resource manager
	void setupResourceManager();

	//
	//bool frameRenderingQueued(const Ogre::FrameEvent& fe); 

protected:

	bool frameStarted(const Ogre::FrameEvent &fe);

	bool frameEnded(const Ogre::FrameEvent &fe);

private:

	OIS::Mouse *mMouse;
	OIS::Keyboard *mKeyboard;
	OIS::InputManager *mInputManager;

private:

	void createInput();
	void destroyInput();
	void captureInput();

};

#endif
