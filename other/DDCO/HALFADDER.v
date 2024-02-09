module halfAdder(Cout,Sum,a,b);
       input a,b;
       output Cout,Sum;
       assign Sum=a^b;
       assign Cout=(a&b);
endmodule
