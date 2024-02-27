module Lab1 (a,b,c,d,f);
    input a,b,c,d;
    output f;
    assign f= (~a & ~c & ~d) | (a & b) | (a & ~c & d);
endmodule