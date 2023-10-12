fn main() {
    let x = (0b0111, true, 'x');
    let y = [1, 2, 3, 4, 5];

    let mut a = 10;
    let b = if a > 5 { 6 } else { 11 };
    for a in [1, 2, 3, 4, 5]{
        println!("Hello {} {} {}", x.0, y[0], a);
    }
    let b = loop {
        if  a >13 {
            break a;
        }
        a+=1;
        println!("{}",a);
        
    };
}
