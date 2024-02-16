module dff(q,qbar,d,clk);
	input d,clk;
    	output q,qbar;
    	wire not1_out,nand1_out,nand2_out;
    	not (not1_out,d);
    	nand (nand1_out,clk,d);
    	nand (nand2_out,clk,not1_out);
    	nand (q,qbar,nand1_out);
    	nand (qbar,q,nand2_out);
endmodule