import json

def extract_links_from_json(json_file):
    links = []
    try:
        with open(json_file, 'r') as file:
            data = json.load(file)
            for key, value in data.items():
                links.append(value)
    except (json.JSONDecodeError, FileNotFoundError):
        print("Error: Invalid JSON file or file not found.")
    return links

def write_links_to_txt(links, output_file):
    with open(output_file, "w") as txt_file:
        for link in links:
            txt_file.write(link + "\n")

if __name__ == "__main__":
    json_file_path = input("Enter the path of the JSON file: ")
    links = extract_links_from_json(json_file_path)
    if links:
        output_file = "txt/output_links.txt"
        write_links_to_txt(links, output_file)
        print(f"Successfully extracted and saved {len(links)} links to {output_file}.")
    else:
        print("No links found in the JSON data.")
