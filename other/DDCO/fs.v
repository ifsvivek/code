
module fs(diff,borrow,a,b,c);
	input a,b,c;
	output diff,borrow;
	assign diff=a^b^c;
	assign borrow=(~a&b)|(b&c)|(~a&c);
endmodule