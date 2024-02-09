module demux8(d,a,b,c,y0,y1,y2,y3,y4,y5,y6,y7);
	input d,a,b,c;
	output y0,y1,y2,y3,y4,y5,y6,y7;
	assign y0=(~a&~b&~c&d);
	assign y1=(~a&~b&c&d);
	assign y2=(~a&b&~c&d);
	assign y3=(~a&b&c&d);
	assign y4=(a&~b&~c&d);
	assign y5=(a&~b&c&d);
	assign y6=(a&b&~c&d);
	assign y7=(a&b&c&d);
endmodule