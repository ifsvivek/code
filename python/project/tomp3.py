import ffmpeg

def convert_and_trim_mp4_to_mp3(input_file, output_file, start_time, end_time):
    input_stream = ffmpeg.input(input_file, ss=start_time, t=end_time - start_time)
    audio_stream = input_stream.audio
    output_stream = ffmpeg.output(audio_stream, output_file, codec='libmp3lame', qscale=0)
    ffmpeg.run(output_stream)

if __name__ == "__main__":
    input_file_path = "input_video.mp4"
    output_file_path = "output_audio.mp3"
    start_time_seconds = 0
    end_time_seconds = 180

    convert_and_trim_mp4_to_mp3(input_file_path, output_file_path, start_time_seconds, end_time_seconds)
