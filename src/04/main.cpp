#[derive(Copy, Clone)]
enum MemoryCell {
    Undefined,
    Defined(u8),
}
enum ExprError {
    Undefined,
    OutOfBound { Index: u8 },
}
struct CPU {
    registers: [MemoryCell; 16],
    memory: [MemoryCell; 1024],
}

impl CPU {
    fn zeroed() -> Self {
        CPU {
            registers: [MemoryCell::Undefined; 16],
            memory: [MemoryCell::Undefined; 1024],
        }
    }
    fn undefined() -> Self {
        CPU {
            registers: [MemoryCell::Undefined; 16],
            memory: [MemoryCell::Undefined; 1024],
        }
    }
    fn evaluate_expr(&self, expr: Expr) -> Result<u8, ExprError> {
        let (slice, address) = match expr {
            Expr::Constant(value) => return Ok(value),
            Expr::Register(register) => (self.registers.as_slice(), register as usize),
            Expr::Memory(address) => (self.memory.as_slice(), address as usize),
        };
    }
    match slice.get(address){
        Some(cell)=>{
            match cell {
                MemoryCell::Undefined() => Err(ExprError::Undefined),
                MemoryCell::Defined(value) => Ok(*value),
            },
            None(ExprError::OutOfBound { address }),
        }
    }
}
enum Expr {
    Constant(u8),
    Register(u8),
    Memory(u32),
}

enum Instruction {
    Print(Expr),
}

fn execute_instruction(cpu: &mut CPU, inst: Instruction) -> Result<()> {
    match inst {
        Instruction::Print(Expr) => {
            let value = 0;
            println!("{value}");
        }
    }
}

fn main() {
    let cpu = CPU::undefined();
    let inst = Instruction::Print(Expr::Constant(5));
    execute_instruction(&mut cpu, inst);
}
