createProject("engine","input","StaticLib")
includedirs { 
    basicIncludes,
    "../rendering/include/glfw/include/"
 }
 
files { 
    "src/input/**.h",
    "src/input/**.hpp",
    "src/input/**.inl",
    "src/input/**.c",
    "src/input/**.cpp" 
}

dofile "arbrook/core/include-core.lua"