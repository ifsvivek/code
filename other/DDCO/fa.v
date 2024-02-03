module fa(sum,cout,a,b,c);
	input a,b,c;
	output sum,cout;
	assign sum=a^b^c;
	assign cout=(a&b)|(b&c)|(a&c);
endmodule