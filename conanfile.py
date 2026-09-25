from conan import ConanFile
from conan.tools.cmake import CMake, cmake_layout


class NlpLowercaseConan(ConanFile):
    name = "nlp-lowercase"
    version = "1.0.0"
    license = "MIT"
    author = "Norberto Burciaga"
    url = "https://github.com/NorbertoBurciaga/nlp-lowercase"
    description = "Tiny C++ static library that lowercases text for NLP preprocessing"
    topics = ("nlp", "text", "lowercase", "conan")
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": False, "fPIC": True}
    exports_sources = "CMakeLists.txt", "src/*", "include/*"
    generators = "CMakeToolchain"

    def config_options(self):
        if self.settings.os == "Windows":
            del self.options.fPIC

    def layout(self):
        cmake_layout(self)

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.set_property("cmake_file_name", "nlp_lowercase")
        self.cpp_info.set_property("cmake_target_name", "nlp::nlp_lowercase")
        self.cpp_info.libs = ["nlp_lowercase"]
