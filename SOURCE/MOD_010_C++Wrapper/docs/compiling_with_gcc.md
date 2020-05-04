# Compiling the project with the gcc compiler

As the Aml.Engine is primarily targeting c# code, it is build on top of the .Net framework.
Therefore the Aml.Engine is a .NET DLL. Since it is [integrated](https://www.nuget.org/packages/Aml.Engine) in the nuget repository, it can easily be used in C# code examples. 
To import this DLL in a C++ project, it has to be so called C++/CLI code, which is C++ code running in the .Net framework.
This C++/CLI code can in the moment only be compiled by the microsoft compiler, because the compiler uses the .Net framework.

As the GCC Compiler can not be integrated with the .Net framework, it is not possible to compile the C++/CLI code.
 
 If the aim is to run the project on Linux, technically it should work, because the framework ``.Net Core`` can run on linux architectures.