struct OpenedFile{
    fd : u32
}

impl Drop for OpenedFile {
    fn drop(&mut self){
        println!("Drop");
    }
}

fn close(file : OpenedFile){
    //destructor file
}

fn main() {
    let file = OpenedFile { fd : 0};
    let file2 = OpenedFile { fd: file.fd };
    close(file); //destructor file
//    close(file);
    //destructor file
}
