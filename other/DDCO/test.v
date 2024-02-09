module demux2(d,a,y0,y1);
input d,a;
output y0,y1;
assign y0=(~a & d);
assign y1=(a & d);
endmodule