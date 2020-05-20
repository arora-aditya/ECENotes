import mosspy
import sys

userid = "680980157"

m = mosspy.Moss(userid, "cc")

# Submission Files
m.addFile(str(sys.argv[1]))
m.addFile(str(sys.argv[2]))
m.addBaseFile(str(sys.argv[3]))


try:
    url = m.send() # Submission Report URL
except:
    print(e)
print ("Report Url: " + url)

# # Save report file
# m.saveWebPage(url, "submission/report.html")
#
# # Download whole report locally including code diff links
# mosspy.download_report(url, "submission/report/", connections=8)
