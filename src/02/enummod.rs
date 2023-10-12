  use foo::CarId;
mod foo{
    //struct
    struct User {
        age: u8,        //256
        alive: bool,    //2
    } //256*2=512

    //Tuple struct
    struct Car(u32, u32, bool);

    //Newtype
    pub struct CarId(pub u32); //cela struktura a atribut   
    pub fn create_car_id(a: u32) ->CarId{
        assert!(a >1000);
        CarId(0)
    }
}

fn bar(a: foo::CarId){
    a.0; //musi byt verejny
    let c = CarId;
}

struct User {
    age: u8,            //256
    alive: bool,        //2
}                       // 256 * 2 = 512

enum PrintType{
    MsgPack,            //1
    Json{ indent: u32 },//1
}                       //1 + 1 = 2


fn print_data(data:  u32, print_type : PrintType){}

fn main() {
    //let mut car = foo::CarId(0);
    //print_data(1, PrintType::Json { indent: 4 });

    let print_type = PrintType::Json { indent: 4 };  
    
    let indent = match print_type {
        PrintType::Json { indent } => indent,
        PrintType::MsgPack => 0,
        _ => 1,

        //[x, xs @ ..]
    };    

    let user = User{ age: 5, alive: true };
    println!("Age: {}\tAlive: {}",user.age, user.alive);
}

enum Document{}
struct PrintJob{
    id : u32,
    start : u32,
    document : Document,
    state : JobState,
} 

enum JobState{
    Queued,
    Printing{ printer : String, },
    Finished{
        printed_pages: u32,
    },
    Error {
        error : String,
    }
}
