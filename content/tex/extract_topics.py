import PyPDF2

# Function to extract topics from the top of a page's content
def extract_topics_from_top(text, max_lines=5):
    parts = text.splitlines()[0].split()
    if not parts or parts[0] != "Matfyz" or not parts[-1].isnumeric():
        print(f"Ignoring header: {parts}")
        return
    matfyz, *topics, pgnum = parts
    return pgnum, topics

# Open and read the PDF file
def extract_topics_from_pdf(pdf_path):
    topics_per_page = {}
    with open(pdf_path, 'rb') as file:
        reader = PyPDF2.PdfReader(file)
        for page_num in range(len(reader.pages)):
            page = reader.pages[page_num]
            text = page.extract_text()
            if not text:
                continue
            res = extract_topics_from_top(text)
            if res is None:
                continue
            pgnum, topics = res
            topics_per_page[pgnum] = topics
    return topics_per_page

# Path to the uploaded PDF file
pdf_path = 'kactl.pdf'

# Extract topics and print them in the required format
topics_per_page = extract_topics_from_pdf(pdf_path)
# output pretty latex code, all topics on the same line
print("\\begin{itemize}[noitemsep]")
print("\\raggedright")
for page, topics in topics_per_page.items():
    print(f"    \\item \\textbf{{Page {page:>2}:}} {', '.join(topics)}")
print("\\end{itemize}")
