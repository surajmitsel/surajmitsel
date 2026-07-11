## Prompt
- To write highly effective prompts for generative AI, you must move from "chatting" to giving structured instructions. AI models perform best when they are given clear guardrails, context, and a specific format.
------------------------------
## 🛠️ The Perfect Prompt Framework: C-R-E-A-T-E
The most reliable way to structure a high-performance prompt is using the CREATE framework. You do not need every element for simple tasks, but combining them guarantees better output.

| Element | What It Means | Example |
|---|---|---|
| Context | The background situation or domain. | "We are launching a new eco-friendly running shoe targeted at urban millennials." |
| Role | The persona or expert mindset the AI should adopt. | "Act as an expert conversion copywriter with 10 years of experience in direct-to-consumer marketing." |
| Explicit Task | The clear, unambiguous action you want the AI to take. | "Write three distinct variants of a Facebook ad headline and primary text." |
| Audience | Who the final output is intended for. | "The tone should appeal to active city dwellers who care about sustainability but prioritize style." |
| Transformation | Rules, constraints, and data to process. | "Keep headlines under 50 characters. Avoid cliché words like 'revolutionary' or 'game-changing'." |
| Execution Format | The exact structure of the final output. | "Format the output as a Markdown table with columns for Headline, Primary Text, and Core Hook Used." |

------------------------------
## 💡 Advanced Prompt Engineering Techniques## 1. Few-Shot Prompting (Give Examples)
AI models learn incredibly well from patterns. Instead of just describing what you want, provide 1 or 2 examples of ideal outputs.

* Bad: "Translate this phrase into professional corporate speak."
* Good:

"Translate informal text into professional corporate speak.
Example 1: 'I forgot about this' ➔ 'Thank you for your patience; this slipped through the cracks.'
Example 2: 'Stop emailing me' ➔ 'Please remove me from this thread as I am no longer involved.'
Input: 'You guys messed up the numbers' ➔"


## 2. Chain-of-Thought (Force Step-by-Step Reasoning)
For logic, math, or complex analysis, explicitly tell the AI to think before answering. This prevents the model from rushing into an incorrect guess.

* Add this phrase to your prompt: "Think step-by-step before arriving at your final answer. Show your reasoning logic in a hidden or separate section."

## 3. Negative Constraints (What NOT to do)
Models are eager to please and often default to generic, wordy fluff. Tell the AI what boundaries it cannot cross. 

* Examples:
* "Do not include an introductory or concluding sentence."
   * "Do not use passive voice."
   * "Write this at a 5th-grade reading level. Do not use industry jargon."

------------------------------
## ❌ Common Pitfalls to Avoid

* Vague Adjectives: Avoid words like "make it good", "make it creative", or "write a detailed report". Instead, use concrete metrics: "Include 3 real-world case studies and limit the report to 500 words." 
* Prompt Megamixes: Do not ask the AI to do 5 completely different tasks in one prompt. Break your workflow into a sequence of prompts (e.g., Prompt 1: Brainstorm ideas ➔ Prompt 2: Outline the best idea ➔ Prompt 3: Write the section). 

------------------------------
If you have a specific task you are working on right now, share it with me! I can show you how to rewrite your current prompt into a highly effective version, or we can look at how to build a system prompt for an AI agent.