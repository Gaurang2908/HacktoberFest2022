from PyPDF2 import PdfFileWriter, PdfFileReader
import getpass  # Syntax- getpass.getpass(prompt=’Password: ‘, stream=None)

pdfwriter = PdfFileWriter()
pdf = PdfFileReader('C:\\Users\\aythi\\OneDrive\\Desktop\\s3\\prp7.pdf')

for page_num in range(pdf.numPages):
    pdfwriter.addPage(pdf.getPage(page_num))  # appending the pages inthe pdf

password = getpass.getpass("Enter password: ")
pdfwriter.encrypt(password)

with open('C:\\Users\\aythi\\OneDrive\\Desktop\\s3\\prp7.pdf', 'wb') as f:
    pdfwriter.write(f)