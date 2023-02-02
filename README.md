# FrenchBakery Dev-Template

The dev template is the development environment we use to write programms for the KIPR Wombat controller. It contains a simple build system and dev container configuration allowing you to develop C and C++ programms for the Wombat controller with the comfort of all of VSCode and full C++ IntelliSense.

## Features

 - Dev Container to provide the preconfigured linux development experience (git, ssh, scp, ...) on any host OS and platform
 - C++ IntelliSense for the aarch64 platform including all standard linux headers and the KIPR standard library headers
 - Simple All-In-One Build system based on Makefile
   - Automatic deployment to the Raspberry Pi (copy files)
   - Automatic remote compilation on the Pi
   - Automatic remote start with local console I/O for debugging and interacting with any programms


## Getting started

To get started developing for the Wombat using this template, either create a fork or an independent copy of the repository and clone it to your machine. A fork offers the benefit of allowing updates with changes from the base repo, in case new features are added to the environment.

Before opening the folder, make sure you have the VSCode Dev Containers extension and docker installed according to the [installation manual](https://code.visualstudio.com/docs/devcontainers/containers). Then use the VSCode command 

```Dev Containers: Open Folder in Container ...```

and select the cloned repository folder. The first time this is done, it will download the container base image and install the development environment and compiler. Then it will open the folder inside the container, like connecting to any remote VSCode server. Every time opening the folder after that, the container is already installed and you will immediately be connected to it.

You can now start creating your code inside the src folder! Any header-only dependencies can be added to the include folder. These will be copied and included in the compilation (Note: the devinclude folder is not supposed to be modified, it is not included in the compilation).

Before compiling and/or running the project, you will have to establish a network connection to the Wombat controller using either an ethernet cable or WiFi. (Note: The Wombat controller has to have a linux user that can be accessed using ssh. This user can be created using the default shell included in the KISS web interface. We have named our user "access") Then create a file called ```env.mk``` and add the username and IP address (or domain) that is used to log in to the Raspberry Pi:

```Makefile
# deployment host config
USER = access
HOST = 10.42.0.149
```

This is all the configuratino needed, however it is recommended to set up SSH key-based authentication to the Wombat, or else you will be typing your password **A LOT** while using the Makefile.

Now you can use any of the provided make targets to deploy, build and run your project:

```bash
make <target>
```

 - ```copy_files```: copies all files required to build the project to a Project folder of the same name as locally (src/, include/, Makefile, env.mk)
 - ```remote_build```: envokes the default make target on the target host to build the project from the (previously copied) source files.
 - ```remote_start```: runs the binary (```run/main```) on the target host (it has to be build beforehand)
 - ```shell```: opens an SSH session to the configured target host
 - ```start```: copies the files, builds the project and runs it on the target all in one command. This just invokes the first three make targets in a row.
 - ```build```: same as ```start``` but without running the binary
 - ```mount```: mounts the Wombat's file system in the "mount" folder in the project directory.
 - ```unmount```: unmounts the Wombat's file system mounted using ```mount```
 - ```clean```: removes any object and binary files. This doesn't do anything in the container because these files are only created during compilation on the target.

The default make target would build the source files but this should never be invoked directly, as that will only work on the Wombat. It is invoked by the ```remote_build``` target on the Wombat via SSH.


## Extension recommendations

It is recommended to install the following VSCode extensions because they are usefull while coding:

 - Git Graph
 - Doxygen Documentation Generator

It is advised not to install the Microsoft Makefile tools, because they may mess with the IntelliSense configuration if not operated carefully.

All of these recommendations are also listed in the ```.vscode/extensions.json``` file.


## Updating

When changes are made to the container configuration, after updating your fork with the latest changes, it is required to rebuild the docker container to accomodate these changes.

Warning: Any software that has been installed in the container or any configurations that are not stored as files in the project folder will be lost after this operation. To prevent this from becomming an issue, we recommend adding these config and install commands to the ```.devcontainer/Dockerfile``` like can be seen with the existing installations. This way, everything will be reinstalled and configured automatically afer rebuilding the container.

To rebuild the container use the following VSCode command:

```Dev Containers: Rebuild Container```


## Improvements and contributions

If you have features you feel should be added to the default installation becaus you use them all the time, don't just add them to your project but instead to the base template so they can be reused for other projects. 

Feel free to open a Pull Request for any additional features, we will be happy to add new usefull features to the template.
