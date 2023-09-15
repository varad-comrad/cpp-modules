#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

#ifdef _WIN32
const char pathsep = '\\';
#else
const char pathsep = '/';
#endif


namespace pathlib {

    namespace fs = std::filesystem;

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

    class IsNotFileError : public std::exception {
        const char* what() const throw() {
            return "Is not a file";
        }
    };

    class IsNotDirectoryError : public std::exception {
        const char* what() const throw() {
            return "Is not a directory";
        }
    };

    class Path {
    
    private:
        std::string path_;
        std::string parent_;
        std::string name_;

    public:

        Path(const Path& path) : path_(path.path_) {
            name_ = path_.substr(path_.find_last_of(pathsep) + 1);
            parent_ = path_.substr(0, path_.find_last_of(pathsep));
        }

        Path(Path&& path) : path_(path.path_) {
            name_ = path_.substr(path_.find_last_of(pathsep) + 1);
            parent_ = path_.substr(0, path_.find_last_of(pathsep));
        }

        Path(const std::string& path) : path_(path) {
            name_ = path_.substr(path_.find_last_of(pathsep) + 1);
            parent_ = path_.substr(0, path_.find_last_of(pathsep));
        }
        
        Path(const char* path){
            std::string aux(path);
            path_ = aux;
            name_ = path_.substr(path_.find_last_of(pathsep) + 1);
            parent_ = path_.substr(0, path_.find_last_of(pathsep));
        }

        friend std::ostream& operator<<(std::ostream& os, const Path& path);
        friend std::ostream& operator<<(std::ostream& os, Path&& path);

        operator std::string() const {
            return path_;
        }

        Path operator/(const Path &other) const {
            return Path(path_ + pathsep + other.name_);
        }

        Path operator/(Path&& other) const {
            return Path(path_ + pathsep + other.name_);
        }

        void operator/=(const Path &other){
            path_ += pathsep + other.name_;
        }

        void operator/=(Path&& other){
            path_ += pathsep + other.name_;
        }

        Path operator+(const Path &other) const {
            return Path(path_ + other.name_);
        }

        Path operator+(Path&& other) const {
            return Path(path_ + other.name_);
        }

        void operator+=(const Path &other){
            path_ += other.name_;
        }

        void operator+=(Path&& other){
            path_ += other.name_;
        }

        Path operator=(const Path& other) const {
            return Path(other.path_);
        }

        Path operator=(Path&& other) const {
            return Path(other.path_);
        }

        bool operator==(const Path& other) const {
            return path_ == other.path_;
        }
        
        bool operator!=(const Path& other) const {
            return path_ != other.path_;
        }

        std::string name() const {
            return name_;
        }

        std::string parent() const {
            return parent_;
        }

        using fstream = std::fstream;
        using ios_base = std::fstream::ios_base;

        bool is_dir() const {
            return fs::is_directory(path_);
        }

        bool is_file() const {
            return fs::is_regular_file(path_);
        }

        bool exists() const {
            return fs::exists(path_);
        }

        void mkdir() const {

        }

        bool is_symlink() const {
            return fs::is_symlink(path_);
        }

        bool is_absolute() const {
            return fs::path(path_).is_absolute();
        }

        bool is_relative() const {
            return fs::path(path_).is_relative();
        }

        bool is_block_device() const {
            return false;
        }

        bool is_char_device() const {
            return false;
        }

        bool is_fifo() const {
            return fs::is_fifo(path_);
        }

        bool is_socket() const {
            return fs::is_socket(path_);
        }

        bool is_reserved() const {
            return false;
        }

        bool is_readonly() const {
            return false;

        }

        bool is_writable() const {
            return false;
        }

        bool is_executable() const {
            return false;
        }

        bool is_readable() const {
            return false;
        }

        bool is_samefile(const Path& other) const {
            return this->absolute() == other.absolute();
        }

        bool is_relative_to(const Path& other) const {
            return false;
        }

        void chmod(int mode) const {

        }

        Path absolute() const {
             return Path(fs::absolute(fs::path(path_)));
        }

        Path relative_to(const Path& other) const {
            return Path(".");

        }

        Path parent_path() const {
            return Path(".");

        }

        Path root() const {
            return Path(".");

        }

        void rmdir() const {

        }

        void symlink_to(const Path& other) const {

        }

        void symlink_to(Path&& other) const {

        }

        void rename(const Path& other) const {

        }

        void rename(Path&& other) const {

        }

        void replace(const Path& other) const {

        }

        void replace(Path&& other) const {

        }

        void unlink() const {

        }

        void touch() const {

        }
        
        fstream open(fstream::ios_base::openmode mode = ios_base::in | ios_base::out) const{
            if (!exists()) {
                throw FileNotFoundError();
            } else if (!is_file()) {
                throw IsNotFileError();
            }
            return fstream(path_, mode);
        }        

        void stat() const {

        }

        // fs::directory_iterator iterdir() const {

        // }

        ~Path() {
        
        }


    };

    std::ostream& operator<<(std::ostream& os, const Path& path) {
        os << path.path_;
        return os;
    }

    std::ostream& operator<<(std::ostream& os, Path&& path) {
        os << path.path_;
        return os;
    }

}

int main(){
    pathlib::Path p("Documents");
    std::cout << p.absolute() << std::endl;
}