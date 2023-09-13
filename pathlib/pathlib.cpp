#include <iostream>
#include <string>

#ifdef _WIN32
const char pathsep = '\\';
#elif __linux__
const char pathsep = '/';
#endif

namespace pathlib {

    class FileNotFoundError : public std::exception {
        const char* what() const throw() {
            return "File not found";
        }
    };

    class FileExistsError : public std::exception {
        const char* what() const throw() {
            return "File exists";
        }
    };

    class DirectoryNotFoundError : public std::exception {
        const char* what() const throw() {
            return "Directory not found";
        }
    };

    class DirectoryExistsError : public std::exception {
        const char* what() const throw() {
            return "Directory exists";
        }
    };


    class Path {
    public:
        Path(const std::string& path) : path_(path) {
            name_ = path_.substr(path_.find_last_of(pathsep) + 1);
            parent_ = path_.substr(0, path_.find_last_of(pathsep));
        }

        Path(std::string&& path) : path_(path) {
            name_ = path_.substr(path_.find_last_of(pathsep) + 1);
            parent_ = path_.substr(0, path_.find_last_of(pathsep));
        }

        friend std::ostream& operator<<(std::ostream& os, const Path& path);

        operator std::string() const {
            return path_;
        }

        Path operator/ (Path&& other) {
            return Path(path_ + pathsep + other.path_);
        }
        
        Path operator/ (std::string& other) {
            return Path(path_ + pathsep + other);
        }
        
        Path operator/ (std::string&& other) {
            return Path(path_ + pathsep + other);
        }

        std::string name() const {
            return name_;
        }

        std::string parent() const {
            return parent_;
        }

        bool is_dir() const {

        }

        bool is_file() const {

        }

        bool exists() const {

        }

        bool mkdir() const {

        }


    private:
        std::string path_;
        std::string parent_;
        std::string name_;
    };

    std::ostream& operator<<(std::ostream& os, const Path& path) {
        os << path.path_;
        return os;
    }

}

int main(){
    pathlib::Path p("/home/fabricio/Documents");
    std::cout << p / "projects" / "" << std::endl;
}