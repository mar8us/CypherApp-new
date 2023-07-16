# CypherApp-new

Hello! 

This is a project created for education. 

Background information for this project:
* Visual Studio 2017 CLR project
* using OpenSSL 3.0 to implement basic cryptography alghoritm like AES, RSA, SHA-2

## Setup
To compile this project, you have to install OpenSSL and add it to Visual Studio. I did this using vcpkg because I think it's a simple way to achieve this.
vcpkg: https://github.com/microsoft/vcpkg

After you installing vcpkg you can proceed to install OpenSSL. Use this command in the terminal:
```
.\vcpkg install openssl:x64-windows
.\vcpkg integrate install //integrate vcpkg with visual studio
```
###Project Configuration
Once OpenSSL has been installed and vcpkg is integrated with Visual Studio, you'll need to configure your project to use OpenSSL. Here are the steps:

*Open the project in Visual Studio: Launch Visual Studio and open the project related to this README.

*Configure project properties: Right click on the project in the Solution Explorer and select "Properties".

*Update include directories:
In the Project Properties window, navigate to Configuration Properties -> VC++ Directories.
In the "Include Directories" line, add the path to the include directory of the OpenSSL installation in vcpkg. The typical path would be: C:\path\to\vcpkg\installed\x64-windows\include.
*Update library directories:

Still in VC++ Directories, go to the "Library Directories" line.
Add the path to the lib directory of the OpenSSL installation in vcpkg. The typical path would be: C:\path\to\vcpkg\installed\x64-windows\lib.
*Link against the OpenSSL libraries:

Go to Configuration Properties -> Linker -> Input.
In the "Additional Dependencies" line, add the names of the OpenSSL library files you want to link against. These will typically be libcrypto.lib and libssl.lib.
Save the project properties: Click "Apply" and then "OK" to save your changes to the project properties.

Once these steps are completed, your project should be set up to use OpenSSL.

Happy coding!
