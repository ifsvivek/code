module mux2(y,d0,d1,a);
output y;
input d0,d1,a;
assign y=(~a& d0)|(a & d1);
endmodule