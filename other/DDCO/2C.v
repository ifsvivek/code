module HalfSub(Borrow,Diff,a,b);
	input a,b;
	output Diff,Borrow;
	assign Diff=a^b;
	assign Borrow=(~a&b);
endmodule
