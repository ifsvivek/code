module p3behav(a, b, c, d, y);
    input a, b, c, d;
    output reg y;

    always @(a, b, c, d) begin 
        y = (a & b) | (c & d);
    end
endmodule
