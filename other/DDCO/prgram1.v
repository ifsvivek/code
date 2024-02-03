module bitadder(x,y,s,c4,c0);
	input[3:0]x;
	input[3:0]y;
	input c0;
	output[3:0]s;
	output c4;
	wire c1,c2,c3;
	fa FA0(s[0],c1,x[0],y[0],c0);
	fa FA1(s[1],c2,x[1],y[1],c1);
	fa FA2(s[2],c3,x[2],y[2],c2);
	fa FA3(s[3],c4,x[3],y[3],c3);
endmodule
