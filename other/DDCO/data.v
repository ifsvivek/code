module p3dataflow(a,b,c,d,y);
	input a,b,c,d;
	output y;
	wire y1,y2;
	assign y1=a&b;
	assign y2=c&d;
	assign y3=y1|y2;
endmodule
