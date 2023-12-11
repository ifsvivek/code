// 4-bit Ripple Carry Adder module
module RippleCarryAdder (
  input [3:0] A, B,  // 4-bit inputs
  input Cin,         // Carry input
  output [3:0] Sum,   // 4-bit sum output
  output Cout         // Carry output
);

  // Internal wire for carry propagation
  wire [3:0] C;

  // Full adder instances
  FullAdder fa0 (.A(A[0]), .B(B[0]), .Cin(Cin), .Sum(Sum[0]), .Cout(C[0]));
  FullAdder fa1 (.A(A[1]), .B(B[1]), .Cin(C[0]), .Sum(Sum[1]), .Cout(C[1]));
  FullAdder fa2 (.A(A[2]), .B(B[2]), .Cin(C[1]), .Sum(Sum[2]), .Cout(C[2]));
  FullAdder fa3 (.A(A[3]), .B(B[3]), .Cin(C[2]), .Sum(Sum[3]), .Cout(Cout));

endmodule

// Full Adder module
module FullAdder (
  input A, B, Cin,    // Inputs
  output Sum, Cout    // Outputs
);

  assign Sum = A ^ B ^ Cin;     // XOR for sum
  assign Cout = (A & B) | (B & Cin) | (A & Cin);  // OR for carry

endmodule

// Testbench module
module RippleCarryAdder_tb;

  // Inputs
  reg [3:0] A, B;
  reg Cin;

  // Outputs
  wire [3:0] Sum;
  wire Cout;

  // Instantiate the RippleCarryAdder module
  RippleCarryAdder uut (
    .A(A),
    .B(B),
    .Cin(Cin),
    .Sum(Sum),
    .Cout(Cout)
  );

  // Initial block for testbench stimulus
  initial begin
    $monitor("Time=%0t A=%b B=%b Cin=%b Sum=%b Cout=%b", $time, A, B, Cin, Sum, Cout);

    // Test case 1
    A = 4'b0010;
    B = 4'b1101;
    Cin = 1;
    #10;  // Simulate for 10 time units

    // Test case 2
    A = 4'b1111;
    B = 4'b0001;
    Cin = 0;
    #10;  // Simulate for 10 time units

    // Add more test cases as needed

    $finish;  // Finish simulation
  end

endmodule