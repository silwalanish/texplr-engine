from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout, CMakeDeps


class TexplrEngineRecipe(ConanFile):
    name = "texplr-engine"
    version = "0.0.1"

    settings = "os", "compiler", "build_type", "arch"
    exports_sources = "CMakeLists.txt", "src/*", "include/*"

    def requirements(self):
        self.requires("glfw/3.4")
        self.requires("glew/2.2.0")
        self.requires("glm/1.0.1")
        self.requires("eventpp/0.1.3")

    def build_requirements(self):
        self.tool_requires("cmake/3.30.1")

    def layout(self):
        cmake_layout(self)

    def generate(self):
        deps = CMakeDeps(self)
        deps.generate()
        tc = CMakeToolchain(self)
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["engine"]
        self.cpp_info.set_property("cmake_file_name", "texplr")
        self.cpp_info.set_property("cmake_target_name", "texplr::engine")
