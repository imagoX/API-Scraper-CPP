# API Scraper Written in C++

<a href="https://colab.research.google.com/github/imagoX/API-Scraper-CPP/blob/main/API_Scraper_CPP.ipynb" target="_parent"><img src="https://colab.research.google.com/assets/colab-badge.svg" alt="Open In Colab"/></a>

## Requirements

1. C++ Compiler
2. vcpkg
3. curl     ``` vcpkg install curl ```
4. libcurl

<br/>

## How to Run?

1. Compile the .cpp file:

    ```
    g++ fetcher.cpp -o fetcher_EXE.exe -I"PATH/TO/vcpkg/installed/x64-windows/include" -L"PATH/TO/vcpkg/installed/x64-windows/lib" -lcurl
    ```

2. A file named fetcher_EXE.exe will be builded.

3. Run the .exe file.