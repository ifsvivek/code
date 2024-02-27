module fullAdder (Cout,Sum,a,b,c);
	input a,b,c;
	output Cout,Sum;
	assign Sum=a^b^c;
	assign Cout=(a&b)|(b&c)|(a&c);
endmodule