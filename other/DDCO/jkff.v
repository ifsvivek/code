module jkff(q,qbar,clk,j,k);
	input clk,j,k;
    output q,qbar;
    wire nand1_out,nand2_out;
    nand (nand1_out,j,clk,qbar);
    nand (nand2_out,k,clk,q);
    nand (q,qbar,nand1_out);
    nand (qbar,q,nand2_out);
endmodule