module bitsub(x,y,d,b4,b0);
	input[3:0]x;
	input[3:0]y;
	input b0;
	output[3:0]d;
	output b4;
	wire b1,b2,b3;
	fs FS0(d[0],b1,x[0],y[0],b0);
	fs FS1(d[1],b2,x[1],y[1],b1);
	fs FS2(d[2],b3,x[2],y[2],b2);
	fs FS3(d[3],b4,x[3],y[3],b3);
endmodule
