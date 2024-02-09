module mux4(y,d0,d1,d2,d3,a,b);
	output y;
	input d0,d1,d2,d3,a,b;
	assign y=(~a&~b&d0)|(~a&b&d1)|(a&~b&d2)|(a&b&d3);
endmodule
