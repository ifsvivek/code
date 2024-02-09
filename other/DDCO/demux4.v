module demux4(d,a,b,y0,y1,y2,y3);
input d,a,b;
output y0,y1,y2,y3;
assign y0=(~a & ~b & d);
assign y1=(~a & b & d);
assign y2=(a &~ b & d);
assign y3=(a & b & d);
endmodule
