module counter(
  input clk,
  input rst_n,
  input up_down,
  output [3:0] count
);

  always @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      count <= 4'b0;
    end else if (up_down) begin
      count <= count + 1'b1;
    end else begin
      count <= count - 1'b1;
    end
  end

endmodule