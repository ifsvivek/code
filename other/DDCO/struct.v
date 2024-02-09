module p3structural (a,b,c,d,y);
	input a,b,c,d;
	output y;
	wire y1,y2;
	and g1(y1,a,b);
	and g2(y2,c,d);
	or g3(y,y1,y2);
endmodule
