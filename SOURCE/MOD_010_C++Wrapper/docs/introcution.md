# C++ Wrapper
## Introduction
The C++ wrapper instructions shall explain how to use the AML.Engine.dll in 
C++ projects running on devices with the .NET Framework version 4.7 or 4.8
 installed. It explains the usage with the Microsoft C++ Compiler and optionally
 also for the GNU C++ compiler.  
It should provide information to a developer for building a C++ project which uses the AML.Engine.dll.

In the best case scenario, it would have worked with both compilers.
Unfortunately this was not possible to achieve. Therefor the wrapper instructions is build on top of the microsoft compiler tools.
However, all findings for compiling the AML.Engine.dll library with the GNU C++ compiler is listed at the bottom.

The wrapper instructions also come with an example project. In case you don't want to follow the instructions of the wrapper, take a look at the [example](../example).

At the last point, there is a glossary for common used terms in this project.

# Project Structure

- C++ Wrapper in the **Microsoft World**
    1. [Preparation](./c++%20wrapper/1_preparation.md)
    1. [Install dependencies](./c++%20wrapper/2_download_aml_engine.md)
    1. [Add sample code](./c++%20wrapper/3_add_sample_code.md)
    1. [Compiling the code](./c++%20wrapper/4_compiling.md)
    
    [Common Compiler Errors](./c++%20wrapper/common_warnings.md)

- C++ Wrapper with **GNU C++ Compiler**
    - [Issues and findings when compiling with gcc](compiling_with_gcc.md)
    
- [Glossary](glossary.md)
